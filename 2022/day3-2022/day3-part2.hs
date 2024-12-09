import System.IO
import qualified Data.Map as Map

-- Mapa de prioridad
priority :: Map.Map Char Int
priority = Map.fromList $ zip (['a'..'z'] ++ ['A'..'Z']) ([1..26] ++ [27..52])

-- Encontrar el componente común en ambas mitades
sameComponent :: (String, String, String) -> Char
sameComponent (x:xs, ys, zs) | elem x ys && elem x zs = x
                             | otherwise = sameComponent (xs, ys, zs)

-- Función principal
main :: IO ()
main = do
    -- Leer archivo
    contents <- readFile "input_day3.txt"
    
    -- Procesar cada línea y calcular la suma total de prioridades
    let linesOfFile = lines contents  -- Convierte el contenido en una lista de líneas
    totalPriority <- processLines linesOfFile 0  -- Inicializa el acumulador de la suma
    putStrLn $ "Suma total de prioridades: " ++ show totalPriority

-- Procesar cada línea y acumular la suma de prioridades
processLines :: [String] -> Int -> IO Int
processLines [] total = return total  -- Cuando no quedan más líneas, devolver la suma total
processLines (x:y:z:lines) total = do
    
    let dictionary = priority
    -- Encontrar el componente común
    let commonComponent = sameComponent (x, y, z)
    -- Buscar el valor de prioridad en el mapa
    let priorityValue = Map.lookup commonComponent dictionary
    -- Imprimir el componente común y su valor de prioridad
    putStrLn $ "Componente común: " ++ [commonComponent]
    case priorityValue of
        Just value -> do
            putStrLn $ "Prioridad: " ++ show value
            -- Sumar el valor de prioridad al total acumulado
            processLines lines (total + value)
        Nothing -> do
            putStrLn "No se encontró la prioridad en el mapa"
            -- Continuar con la siguiente línea sin sumar
            processLines lines total